// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gen_tasks2.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 11:04:12 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 12:31:57 by ngoguey          ###   ########.fr       //
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

namespace lol {
typedef std::unordered_set<unsigned int> shapehset_t;
typedef std::unordered_map<unsigned int, Piece> uidhmap_t;
typedef std::multimap<unsigned int, unsigned int> shapemmap_t;
}

class ComboGenerator
{
private:
	/* ATTRIBUTES ******************* */
	static constexpr unsigned int numShape = 19;
	static constexpr unsigned int numValidUid = 113;
	unsigned int const _pc_count;

	using shapehset_t = lol::shapehset_t;
	shapehset_t const _shapesHSet;/* 19 (Piece.shape) */

	using uidhmap_t = lol::uidhmap_t;
	uidhmap_t const _uidsHMap;/* 113 (Piece.uid * Piece) */

	using shapemmap_t = lol::shapemmap_t;
	shapemmap_t const _shapesMMap;/* 113 (Piece.shape * Piece.uid) */

	typedef std::vector<shapemmap_t::const_iterator> uidcombo_t;
	struct HashCombo {
		std::size_t operator ()(uidcombo_t const &combo) const {
			std::size_t h;

			for (auto const &it : combo)
				h += std::hash<unsigned int>()(it->second);
			return 0;
		}
	};
	typedef std::unordered_set<uidcombo_t, HashCombo> combohset_t;
	combohset_t _combosHSet;

public:
	/* CONSTRUCTION ***************** */
	ComboGenerator(unsigned int pc_count, shapehset_t shapesHSet
			   , uidhmap_t uidsHMap, shapemmap_t shapesMMap)
		: _pc_count(pc_count), _shapesHSet(shapesHSet)
		, _uidsHMap(uidsHMap), _shapesMMap(shapesMMap) {

		assert(numShape == _shapesHSet.size());
		assert(numValidUid == _uidsHMap.size());
		assert(numValidUid == _shapesMMap.size());
	}

	~ComboGenerator(){}

	ComboGenerator() = delete;
	ComboGenerator(ComboGenerator const &src) = delete;
	ComboGenerator(ComboGenerator &&src) = delete;
	ComboGenerator &operator=(ComboGenerator const &rhs) = delete;
	ComboGenerator &operator=(ComboGenerator &&rhs) = delete;

private:
	/* INTERNAL ******************** */
	unsigned int _randomShape(void) const {

		int const n = std::rand() % numShape;
		int i = 0;

		for (auto t : _shapesHSet)
			if (i++ == n)
				return t;
		assert(false); /* should not be reached */
	}
	shapemmap_t::const_iterator _randomPieceOfShape(unsigned int shp) const {

		unsigned int const n = std::rand() % _shapesMMap.count(shp);
		auto const range = _shapesMMap.equal_range(shp);
		int i = 0;

		for (auto it = range.first; it != range.second; ++it)
			if (i++ == n)
				return it;
		assert(false); /* should not be reached */
	}

	shapemmap_t::const_iterator _randomUid(void) const {

		return _randomPieceOfShape(_randomShape());
	}

	/* Circularily increments an iterator over the Multimap */
	shapemmap_t::const_iterator _nextUid(
		shapemmap_t::const_iterator const &it) const {

		shapemmap_t::const_iterator ret;

		ret = std::next(it);
		if (ret == _shapesMMap.end())
			return _shapesMMap.begin();
		return ret;
	}

	/* Generates a combo, may exist in _combosHSet */
	uidcombo_t _randomComboRaw(void) const {

		uidcombo_t ret;

		for (auto &uid : ret)
			uid = _randomUid();
		return ret;
	}

	/* Increments a combo over 1 or more componants */
	void _incrementCombo(uidcombo_t &combo, uidcombo_t const &comboRand) const {

		int level;
		shapemmap_t::const_iterator it;

		level = _pc_count;
		do {
			--level;
			combo[level] = _nextUid(combo[level]);
		} while (combo[level] == comboRand[level]);
		return ;
	}

	/* Generates a combo, not existing in _combosHSet */
	uidcombo_t _randomCombo(void) const {

		uidcombo_t const comboRand(_randomComboRaw());
		uidcombo_t combo(comboRand);

		while (_combosHSet.find(combo) != _combosHSet.end())
			_incrementCombo(combo, comboRand);
		return combo;
	}

};
