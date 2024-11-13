[![INFORMS Journal on Computing Logo](https://INFORMSJoC.github.io/logos/INFORMS_Journal_on_Computing_Header.jpg)](https://pubsonline.informs.org/journal/ijoc)

<!-- # 2024.0591 -->

# Influence Minimization via Blocking Strategies

This archive is distributed in association with the [INFORMS Journal on Computing](https://pubsonline.informs.org/journal/ijoc) under the [MIT License](LICENSE).

The software and data in this repository are a snapshot of the software and data that were used in the research reported in the paper [Influence minimization via blocking strategies](https://doi.org/10.1287/ijoc.2024.0591) by Jiadong Xie, Fan Zhang, Kai Wang, Jialu Liu, Xuemin Lin, and Wenjie Zhang.

## Cite

To cite the contents of this repository, please cite both the paper and this repo, using their respective DOIs.

[https://doi.org/10.1287/ijoc.2024.0591](https://doi.org/10.1287/ijoc.2024.0591)

[https://doi.org/10.1287/ijoc.2024.0591.cd](https://doi.org/10.1287/ijoc.2024.0591.cd)

Below is the BibTex for citing this snapshot of the repository.

```
@article{IM2024,
  author       = {Jiadong Xie and
                  Fan Zhang and
                  Kai Wang and
                  Jialu Liu and
                  Xuemin Lin and
                  Wenjie Zhang},
  publisher =     {INFORMS Journal on Computing},
  title =         {Influence Minimization via Blocking Strategies},
  year =          {2024},
  doi =           {10.1287/ijoc.2024.0591.cd},
  url =           {https://github.com/INFORMSJoC/2024.0591},
}  
```



## Datasets

The experiments are performed on 8 datasets sourced from [SNAP](http://snap.stanford.edu), also accessible through the files under [/data/](/data/).

In dataset files, the first line specifies the vertex count `n` and edge count `m`. Each subsequent line features two integers `u v` representing a directed edge $(u,v)$.

Prior to executing our algorithms, it is essential to first process the downloaded datasets from [SNAP](http://snap.stanford.edu) using the provided data processing scripts at [/scripts/DataProcess.cpp](/scripts/DataProcess.cpp).
Specifically, utilize `g++ -o DataProcess DataProcess.cpp -std=c++11 -O3` for compilation, run the code with `./DataProcess`, and input the dataset name when run.


## Run Algorithms

### Compile

Compile the codes either by utilizing the scripts under [/scripts/compile.sh](./scripts/compile.sh) or by directly employing the subsequent commands.

```shell
g++ -o AdvancedGreedy AdvancedGreedy.cpp -std=c++11 -O3
g++ -o GreedyReplace GreedyReplace.cpp -std=c++11 -O3
```

### Algorithms

* **AdvancedGreedy (AG)**: Algorithm 3 that contains Algorithm 2 to accelerate the baseline greedy algorithm.

* **GreedyReplace (GR)**: Our GreedyReplace algorithm (Algorithm 4).

All the algorithms can be run as follows.

For example, we use `./GreedyReplace` to run the code, and then input the name of the dataset, the influence model, the propagation model, the number of sources and the budget by the keyboard.

```shell
dataset: sample_graph.txt
influence model (0: IC model; 1: LT model): 0
propagation model (0: TR model; 1: WC model): 0
number of sources : 3
budget: 3
```
Note that we use the same rand parameter to ensure all the algorithms have the same seed set: `mt19937 rand_num(20220708)`.

### Results

The program will print the sources which are chosen randomly and the time for loading the dataset.

```shell
source: 24 28 36 
Finish loading dataset. time : 0.000569s.
```

The experiment results will be saved in [/results](/results/), e.g., [/results/GR-IC-TR-sample_graph.txt](/results/GR-IC-TR-sample_graph.txt).

Three numbers in the results mean `budget`, `expected spread` and `running time (s)`, respectively.

Detailed results for all the tested instances can be found in [/results/results.pdf](/results/results.pdf).

#### Environment

The experiments in our paper are performed on a CentOS Linux serve (Release 7.5.1804) with Quad-Core Intel Xeon CPU (E5-2640 v4 @ 2.20GHz) and 128G memory. All the algorithms are implemented in C++. The source code is compiled by GCC(7.3.0) under O3 optimization.