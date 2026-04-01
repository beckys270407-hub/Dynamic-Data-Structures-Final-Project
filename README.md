# Dynamic-Data-Structures-Final-Project
Dynamic Data Structures Lab Final Project Repository

Mafia Succession System - Dynamic Data Structures

Description

This project is a C++ implementation of a hierarchical management system for an Italian Mafia family. The system manages the succession of power using a Binary Tree structure. It handles data ingestion from CSV files, real-time updates of family members, and complex automated logic to determine the next Boss based on specific criteria such as age, legal status, and life status.

Project Structure

To comply with the technical requirements, the project is organized as follows:

bin: Contains the program executable and the data.csv input file.

src: Contains all .cpp and .h source files.

README.md: Project documentation and instructions.

Requirements and Logic

The system implements the following core functionalities:

Binary Tree Ingestion: Loads data from .csv using a custom parser. No vectors are utilized in accordance with project constraints.

Current Succession: Displays all living family members eligible for the position.

Automated Succession: When a Boss dies, enters prison, or exceeds 70 years of age, the system searches the tree for the most suitable heir based on:

Direct successors (children nodes).

Cousin branches (sibling's children).

Closest available ancestor with eligible successors.

Node Management: Allows editing member details, excluding unique IDs and parent IDs.

Authors

Rebecca Saras - Computer Engineering Student

Angelica Rodriguez - Computer Engineering Student
