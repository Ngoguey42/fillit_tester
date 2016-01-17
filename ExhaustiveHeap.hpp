// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ExhaustiveHeap.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/17 16:25:15 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/17 19:57:19 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EXHAUSTIVEHEAP_HPP
# define EXHAUSTIVEHEAP_HPP

# include <vector>
# include <array>

# include "PiecesStash.hpp"

class ExhaustiveHeap
{

private:
	/* TYPES ************************ */
	struct SubLevel
	{
		unsigned int uid;
		unsigned int count;
		/*
		** If SubLevel is terminal:
		**   If Terminal is available:
		**         count == 1
		**   If Terminal is NOT available:
		**         count == 0
		** If SubLevel is NOT terminal:
		**   count == nAvailable is its SubLevels
		*/
	};
	struct Level
	{
		typedef std::array<SubLevel, PiecesStash::numValidUid> array_t;
		array_t sublvls;
	};

private:
	/* ATTRIBUTES ******************* */
	std::vector<Level> _heap;
	unsigned int const _npcs;
	unsigned int _count;

public:
	/* CONSTRUCTION ***************** */
	ExhaustiveHeap(PiecesStash const &ps, unsigned int npcs);
	~ExhaustiveHeap();

	ExhaustiveHeap() = delete;
	ExhaustiveHeap(ExhaustiveHeap const &src) = delete;
	ExhaustiveHeap(ExhaustiveHeap &&src) = delete;
	ExhaustiveHeap &operator=(ExhaustiveHeap const &rhs) = delete;
	ExhaustiveHeap &operator=(ExhaustiveHeap &&rhs) = delete;

public:
	/* EXPOSED ********************** */
	void randomPop(std::vector<unsigned int> &combo);

private:
    /* INTERNAL ********************* */
	void _allocHeap(PiecesStash const &ps, size_t heap_sizei);
	void _finalizeHeap(unsigned int depth, unsigned int nleaves);


};

#endif /* ************************************************ EXHAUSTIVEHEAP_HPP */
