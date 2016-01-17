// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gen_tasks2.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 11:04:12 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 16:08:24 by ngoguey          ###   ########.fr       //
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

struct PiecesStash
{
public:
	/* TYPES ************************ */
	typedef std::unordered_set<unsigned int> shapehset_t;
	typedef std::unordered_map<unsigned int, Piece> uidhmap_t;
	typedef std::multimap<unsigned int, unsigned int> shapemmap_t;

private:
	/* ATTRIBUTES ******************* */
	shapehset_t _shapesHSet;
	uidhmap_t _uidsHMap;
	shapemmap_t _shapesMMap;

public:
	/* CONSTRUCTION ***************** */
	PiecesStash() : _shapesHSet{}, _uidsHMap{}, _shapesMMap{} {

		Piece p = {"....", "....", "....", "...."};

		_gen(p, 0, 0);
		return ;
		}
	~PiecesStash() {}

	PiecesStash(PiecesStash const &) = delete;
	PiecesStash(PiecesStash &&) = delete;
	auto operator=(PiecesStash const &) = delete;
	auto operator=(PiecesStash &&) = delete;

public:
	/* EXPOSED ********************** */
	shapehset_t const &shapesHSet(void) const {
		return _shapesHSet;
	}
	uidhmap_t const &uidsHMap(void) const {
		return _uidsHMap;
	}
	shapemmap_t const &shapesMMap(void) const {
		return _shapesMMap;
	}

private:
	/* INTERNAL ********************* */
	void _savePiece (Piece const &pc) {

		unsigned int const shape = pc.shape();
		unsigned int const uid = pc.uid();

		_shapesHSet.insert(shape);
		_uidsHMap.insert({uid, pc});
		_shapesMMap.insert({shape, uid});
		return ;
	}

	void _gen(Piece &p, int count, int istart) {

		int y;
		int x;

		if (count < 4)
		{
			for (int i = istart; i < 16; i++)
			{
				y = i / 4;
				x = i % 4;
				p.val[y][x] = '#';
				_gen(p, count + 1, i + 1);
				p.val[y][x] = '.';
			}
		}
		else if (p.adjDiff() >= 3)
			_savePiece(p);
		return ;
	}
};


class ExhaustiveHeap
{


public:
	/* CONSTRUCTION ***************** */
	~ExhaustiveHeap(){}

	ExhaustiveHeap() = delete;
	ExhaustiveHeap(ExhaustiveHeap const &src) = delete;
	ExhaustiveHeap(ExhaustiveHeap &&src) = delete;
	ExhaustiveHeap &operator=(ExhaustiveHeap const &rhs) = delete;
	ExhaustiveHeap &operator=(ExhaustiveHeap &&rhs) = delete;

};

class ComboGenerator
{
private:
	/* ATTRIBUTES ******************* */
	static constexpr unsigned int numShape = 19;
	static constexpr unsigned int numValidUid = 113;
	unsigned int const _pc_count;

	using shapehset_t = ValidPiecesGenerator::shapehset_t;
	shapehset_t const _shapesHSet;/* 19 (Piece.shape) */

	using uidhmap_t = ValidPiecesGenerator::uidhmap_t;
	uidhmap_t const _uidsHMap;/* 113 (Piece.uid * Piece) */

	using shapemmap_t = ValidPiecesGenerator::shapemmap_t;
	shapemmap_t const _shapesMMap;/* 113 (Piece.shape * Piece.uid) */

	typedef std::vector<shapemmap_t::const_iterator> uidcombo_t;
	struct HashCombo {
		std::size_t operator () (uidcombo_t const &combo) const {
			std::size_t h;

			for (auto const &it : combo)
				h += std::hash<unsigned int>()(it->second);
			return 0;
		}
	};
public:
	typedef std::unordered_set<uidcombo_t, HashCombo> combohset_t;
private:
	combohset_t _combosHSet;

public:
	/* CONSTRUCTION ***************** */
	ComboGenerator(unsigned int pc_count, shapehset_t &&shapesHSet
				   , uidhmap_t &&uidsHMap, shapemmap_t &&shapesMMap)
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
	/* INTERNAL ********************* */
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

		for (int i = 0; i < _pc_count; i++)
			ret.push_back(_randomUid());
		return ret;
	}

	/* Increments a combo over 1 or more components */
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

public:
#define D(V) static_cast<double>((V))
#define UI(V) static_cast<unsigned int>((V))
	void gen(unsigned int size) {

		size = UI(std::min(D(size), std::pow(D(numValidUid), D(_pc_count))));
		_combosHSet.clear();
		_combosHSet.reserve(size);
		for (int i = 0; i < size; i++)
		{
			if (i % 1000 == 0)
				std::cerr << "Noooooo" << i  << std::endl;
			_combosHSet.insert(_randomCombo());
		}
		return ;
	}

	combohset_t::const_iterator begin(void) const {

		return _combosHSet.begin();
	}
	combohset_t::const_iterator end(void) const {

		return _combosHSet.end();
	}

	void convertCombo(combohset_t::const_iterator const &it
					  , std::vector<Piece const *> &vec) const {

		uidcombo_t const &combo = *it;
		int i;

		i = 0;
		assert(vec.size() == _pc_count);
		vec.reserve(_pc_count);
		for (auto const &uidIt : combo)
			vec[i++] = &_uidsHMap.at(uidIt->second);
		return ;
	}
};

char const b62[] = "0123456789"
				  "abcdefghijklmnopqrstuvwxyz"
				  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static std::string itostrb62(unsigned int i)
{
	std::string str;

	if (i == 0)
		return "0";
	while (i != 0)
	{
		str.insert(str.begin(), b62[i % 62]);
		i /= 62;
	}
	return str;
}

static std::string filename_of_pcvec(std::vector<Piece const*> const &pcvec)
{
	std::string ret("./map/");

	for (auto const &p : pcvec)
	{
		ret.append(itostrb62(p->uid()));
		ret.append("_");
	}
	if (ret.size() > 200)
	{
		ret.erase(200);
		ret.append("...");
	}
	ret.append(".fillit");
	return ret;
}


static auto build_files_and_tests(
	ComboGenerator &cg, char const *const av[], int const pptest)
	-> std::vector<UnitTest>
{
	std::vector<UnitTest> tasks;
	std::vector<Piece const *> pcvec(pptest);
	auto it = cg.begin();
	auto const ite = cg.end();
	std::string fname;
	std::ofstream f;

	while (it != ite)
	{
		cg.convertCombo(it, pcvec);
		fname = filename_of_pcvec(pcvec);
		f.open(fname, std::ios_base::out | std::ios_base::trunc);
		assert(f.good()); /* file creation failed */
		for (auto const &p : pcvec)
		{
			if (&p != &*pcvec.begin()) /* funny line, but it works!!! */
				f << '\n';
			p->dump(f);
		}
		assert(f.good()); /* file write failed */
		f.close();
		assert(f.good()); /* file close failed */
		tasks.push_back(UnitTest(av[3], fname));
		tasks.push_back(UnitTest(av[4], fname));
		it++;
	}
	return std::move(tasks);
}

#define MVGET(TUP, I) std::move(std::get<I>(TUP))
std::vector<UnitTest> build_tasks(char const *const av[])
{
	int const pptest = std::atoi(av[1]);
	int const ntests = std::atoi(av[2]);
	auto pcs = ValidPiecesGenerator()();
	ComboGenerator cg(pptest, MVGET(pcs, 0), MVGET(pcs, 1), MVGET(pcs, 2));
	int err;

	if (pptest < 0)
	{
		std::cerr << "Bad grids per tests " << pptest << std::endl;
		::exit(1);
	}
	if (ntests <= 0)
	{
		std::cerr << "Bad num tests " << ntests << std::endl;
		::exit(1);
	}
	std::cout << "\rRemoving ./map ./log                      ";
	std::cout.flush();
	err = ::system("rm -rf map log; mkdir -p log map; false");
	assert(err >= 0);
	std::cout << "\rGenerating combinations                   ";
	std::cout.flush();
	cg.gen(ntests);
	std::cout << "\rGenerating map files                      ";
	std::cout.flush();
	return build_files_and_tests(cg, av, pptest);
}
