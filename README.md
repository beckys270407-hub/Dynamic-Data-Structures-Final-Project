<h1 align="center">⚠️☠️🚨 PROJECT: THE ITALIAN MAFIA (SUCCESSION SYSTEM)⚠️☠️🚨</h1>

<p align="center">
<img src="https://img.shields.io/badge/STATUS-CONFIDENTIAL-red?style=for-the-badge" />
<img src="https://img.shields.io/badge/LANGUAGE-C%2B%2B-black?style=for-the-badge&logo=c%2B%2B" />
<img src="https://img.shields.io/badge/STRUCTURE-BINARY_TREE-B70000?style=for-the-badge" />
</p>

<p align="justify">
Facing instability in the selection of the next leader, the Family has developed this technological prototype. 
The system processes the lineage through a <b>Binary Tree</b> (without the use of vectors) to guarantee that the 
succession is maintained under the strictest codes of honor and legal availability.
</p>

<hr>

<h3>👥 CLAN MEMBERS</h3>
<ul>
<li><b>Angelica Rodriguez</b> - <i> C.i: 32.220.574</i></li>
<li><b>Rebecca Saras</b> - <i> C.i: 32.039.073</i></li>
</ul>

<hr>

<h3>📂 FILE ORGANIZATION</h3>
<p>Following the delivery regulations, the project is structured as follows:</p>
<table>
<tr>
<td><b>📁 bin/</b></td>
<td>Contains the <code>succession_system</code> executable and the <code>family_data.csv</code> file (required data location).</td>
</tr>
<tr>
<td><b>📁 src/</b></td>
<td>Contains the full source code (<code>.cpp</code>, <code>.hpp</code>, and <code>.h</code> files).</td>
</tr>
</table>

<hr>

<h3>📜 SUCCESSION PROTOCOL (IRON RULES)</h3>
<p>The system assigns a new Boss automatically if the current one passes away, is imprisoned, or exceeds 70 years of age, following this priority order:</p>
<ul>
<li><b>Phase 1:</b> The first successor found alive and out of prison within their own subtree.</li>
<li><b>Phase 2:</b> If there are no direct successors, the boss is the first eligible successor found in the tree of the boss's other successor.</li>
<li><b>Phase 3:</b> If no free candidates can be found, the same rules apply to members in prison, starting from the one closest to the current boss.</li>
<li><b>Phase 4:</b> Search for the closest boss with two free successors and choose the first eligible successor found.</li>
</ul>

<hr>

<h3>📊 DATA FORMAT (.CSV)</h3>
<p>The system converts data from the <code>family_data.csv</code> file considering the following columns:</p>
<code>id, name, last_name, gender, age, id_boss, is_dead, in_jail, was_boss, is_boss</code>

<hr>

<h3>🚀 OPERATING INSTRUCTIONS</h3>
<p>To compile and execute the system, ensure you are in the project root directory and follow these commands:</p>

<h4>1. Compilation</h4>
<p>Use the <code>g++</code> compiler to link all source files from <code>src/</code> and output the binary to the <code>bin/</code> folder:</p>

```bash
g++ src/*.cpp -o bin/succession_system