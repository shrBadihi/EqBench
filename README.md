# EqBench
EqBench is a collection of equivalent and non-equivalent **Java** and **C** programs with the goal of advancing software engineering research.
It unifies and extends benchmarks used in earlier works contributing **135 equivalent** and **113 non-equivalent** cases, which we capture in both C and Java,
to facilitate applicability for different equivalence checking techniques.

## Data Representation
The structure of the dataset is shown below:
<img src="/img/structure.png" width="200">

The archive is organized by **18** major directories corresponding to 18 benchmarks.
Inside each benchmark directory, we have one folder for each program.
Since we have both equivalent and non-equivalent pairs for each program, we provide two sub-folders
within each program directory, i.e., *Eq* and *Neq*.
Inside each of the program pair sub-directories, there are four versions: 
two written in **Java (oldV.java and newV.java)** and two written in **C (oldV.c and newV.c)**.

For each Eq and Neq versions, we also provide a file, named *Desc.json*, containing the
meta-data written in the JSON format.

The file is structured as follows.

* **Benchmark name**: the name of the benchmark which the program belongs to,
* **Program name**: the name of the program,
* **LOC**: the number of lines of code,
* **# loops**: the number of loops (bounded or un-bounded),
* **# non-linear arithmetic**: the number of non-linear arithmetics,
* **Changes**: the type and the location of injected changes,
* **Counter-example**: values for input parameters making two programs non-equivalent (for Neq cases only).

The below figure shows an example of the meta-data for the *sign* program in the
*airy* benchmark:

![](/img/desc.png =250x)

In addition, to ensure consistency of the dataset, we provide a schema template (*EqDescTemplate.json* and *NeqDescTemplate.json*) describing the required meta-data for each benchmark as a partof the dataset.
