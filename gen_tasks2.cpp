
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
	typedef std::unordered_set<unsigned int> shapehset_t;
	typedef std::unordered_map<unsigned int, Piece> uidhmap_t;
	typedef std::multimap<unsigned int, unsigned int> shapemmap_t;
	typedef std::vector<unsigned int> uidcombo_t;
	// typedef std::unordered_set<uidcombo_t> combohset_t;

	/* ATTRIBUTES ******************* */
	static unsigned int constexpr numShape = 19;
	static unsigned int constexpr numValidUid = 113;
	unsigned int const _pc_count;

	shapehset_t _shapesHSet;
	uidhmap_t _uidsHMap;
	shapemmap_t _shapesMMap;
	// combohset_t _combosHSet;

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
	unsigned int randomShape(void)
	{
		int const n = std::rand() % numShape;
		int i = 0;

		for (auto t : _shapesHSet)
			if (i++ == n)
				return t;
		assert(false); /* should not be reached */
	}
	shapemmap_t::const_iterator randomPieceOfShape(unsigned int shp)
	{
		unsigned int const n = std::rand() % _shapesMMap.count(shp);
		auto const range = _shapesMMap.equal_range(shp);
		int i = 0;

		for (auto it = range.first; it != range.second; ++it)
			if (i++ == n)
				return it;
		assert(false); /* should not be reached */
	}

	shapemmap_t::const_iterator randomUid(void) {
		return randomPieceOfShape(randomShape());
	}
	
	// combo_t makeCombo(void) {
		// combo_t combo(this->_pc_count);

		// for (int i = 0; i < this->_pc_count; i++)
			// combo[i]
	// }

};
