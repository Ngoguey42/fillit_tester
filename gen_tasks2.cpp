// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gen_tasks2.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 11:04:12 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 12:03:04 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tester.hpp"

// # include <unordered_map>
// # include <map>
// # include <unordered_set>
// # include <set>
// # include <vector>

// # include <cstdlib>
// # include <fstream>
// # include <assert.h>


struct Piece
{
	char    val[4][5];
	unsigned int adjDiff(void) const { /* used to disambiguate valid and invalid pieces */
		unsigned int    acc = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 3; x++)
				if (val[y][x] == '#' && val[y][x + 1] == '#')
					acc++;
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 4; x++)
				if (val[y][x] == '#' && val[y + 1][x] == '#')
					acc++;
		return acc;
	}
	unsigned int shape(void) const { /* used to disambiguate the 19 different shapes */
		int             pos = 0;
		unsigned int    h = 0;
		int             fx = -1;
		int             fy = -1;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				if (val[y][x] == '#')
				{
					if (fx < 0)
						fx = x, fy = y;
					else
					{
						h += (x - fx + 2) << 4 * pos++;
						h += (y - fy + 2) << 4 * pos++;
					}
				}
		return h;
	}
	unsigned int uid(void) const { /* used to disambiguate the 2^(4*4) different grids */
		unsigned int h = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				h = (h << 1) + (this->val[y][x] == '#' ? 1 : 0);
		return h;
	}
	void dump(std::ofstream &os) const {
		for (auto const &l : val)
			os << l << '\n';
	}
};

class TasksStash
{
private:
	/* ATTRIBUTES ******************* */
	static constexpr unsigned int numShape = 19;
	static constexpr unsigned int numValidUid = 113;
	unsigned int const _pc_count;

	typedef std::unordered_set<unsigned int> shapehset_t;
	shapehset_t _shapesHSet;/* 19 (Piece.shape) */

	typedef std::unordered_map<unsigned int, Piece> uidhmap_t;
	uidhmap_t _uidsHMap;/* 113 (Piece.uid * Piece) */

	typedef std::multimap<unsigned int, unsigned int> shapemmap_t;
	shapemmap_t _shapesMMap;/* 113 (Piece.shape * Piece.uid) */

	typedef std::vector<shapemmap_t::const_iterator> uidcombo_t;
	// typedef std::vector<unsigned int> uidcombo_t;
	struct Hash {
		std::size_t operator ()(uidcombo_t const &combo) {
			std::size_t h;

			for (auto const &it : combo)
				h += std::hash<unsigned int>()(it->second);
			return 0;
		}
	};
	typedef std::unordered_set<uidcombo_t, Hash> combohset_t;
	combohset_t _combosHSet;

public:
	/* CONSTRUCTION ***************** */
	TasksStash(unsigned int pc_count) : _pc_count(pc_count){

		assert(numShape == _shapesHSet.size());
		assert(numValidUid == _uidsHMap.size());
		assert(numValidUid == _shapesMMap.size());
	}

	~TasksStash(){}

	TasksStash() = delete;
	TasksStash(TasksStash const &src) = delete;
	TasksStash(TasksStash &&src) = delete;
	TasksStash &operator=(TasksStash const &rhs) = delete;
	TasksStash &operator=(TasksStash &&rhs) = delete;

	/* ***************** */
	// auto generate(unsigned int count);

	// auto begin();
	// auto end();

private:
	/* INTERNAL ******************** */
	unsigned int _randomShape(void) {

		int const n = std::rand() % numShape;
		int i = 0;

		for (auto t : _shapesHSet)
			if (i++ == n)
				return t;
		assert(false); /* should not be reached */
	}
	shapemmap_t::const_iterator _randomPieceOfShape(unsigned int shp) {

		unsigned int const n = std::rand() % _shapesMMap.count(shp);
		auto const range = _shapesMMap.equal_range(shp);
		int i = 0;

		for (auto it = range.first; it != range.second; ++it)
			if (i++ == n)
				return it;
		assert(false); /* should not be reached */
	}

	shapemmap_t::const_iterator _randomUid(void) {

		return _randomPieceOfShape(_randomShape());
	}
	// uidcombo_t _comboFromComboit(uiditcombo_t const &combo) {

	// 	uidcombo_t ret(combo.size());
	// 	auto outputit = ret.begin();

	// 	for (auto const &inputit : combo)
	// 		*outputit++ = inputit->second;
	// 	return ret;
	// }
	shapemmap_t::const_iterator _nextUid(shapemmap_t::const_iterator const &it){

		shapemmap_t::const_iterator ret;

		ret = std::next(it);
		if (ret == _shapesMMap.end())
			return _shapesMMap.begin();
		return ret;
	}

	uidcombo_t _randomCombo(void) {

		uidcombo_t comboRand(_pc_count);
		uidcombo_t combo;
		int level;
		shapemmap_t::const_iterator it;

		for (auto &uid : comboRand)
			uid = _randomUid();
		combo = comboRand;
		level = _pc_count - 1;
		it = comboRand[level];
		while (_combosHSet.find(combo) != _combosHSet.end())
		{
			assert(level >= 0);
			it = _nextUid(it);
			combo[level] = it;
			if (it == comboRand[level])
			{
				level--;
				it = comboRand[level];
			}
		}
		return combo;
	}

};
