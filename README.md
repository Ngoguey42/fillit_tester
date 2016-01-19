
```
/*
** clang++ -O2 -std=c++14 main.cpp report.cpp gen_tasks.cpp execute.cpp && time ./a.out 3 1000 ./fillita ./fillitb
** *
**   The preceding command:
** 1. compiles the tester
** 2. removes ./map and ./log directories
** 3. generates 1000 random .fillit files containing 3 pieces in ./map
** 4. runs in parallel the two given binaries over those maps
** 5. computes a report, and logs errors in ./log
** *
** *
** av[1] pieces per test (0+)
** av[2] num tests (1+)
** av[3] binary 1
** av[4] binary 2
*/
```

```
#procedure for angagnie:
clang++ -std=c++14 -O2 ExhaustiveHeap.cpp Piece.cpp PiecesStash.cpp SuperficialHSet.cpp execute.cpp gen_tasks.cpp main.cpp report.cpp #compilation
git clone https://github.com/mfortin42/fillit wide #clone wide-aze fillit
cd wide ; make ; cd ..
git clone vogsphere@vogsphere.42.fr:intra/2015/activities/fillit/angagnie anga
cd anga ; make ; cd ..

./a.out 1 113 ./anga/fillit ./wide/fillit
./a.out 2 20000 ./anga/fillit ./wide/fillit
./a.out 3 1000 ./anga/fillit ./wide/fillit
./a.out 4 1000 ./anga/fillit ./wide/fillit
./a.out 5 1000 ./anga/fillit ./wide/fillit
./a.out 6 1000 ./anga/fillit ./wide/fillit
./a.out 7 1000 ./anga/fillit ./wide/fillit
```


todo:
- dispatch includes in .cpp files
- use clock instead of chrono for some measures
- screenshot
- more info in readme (WORK_TIMEOUT, NUM_WORKERS in tester.hpp) etc...
- more timings info
