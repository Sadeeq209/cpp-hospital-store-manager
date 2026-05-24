# Hospital Store & Inventory System (Medical Database Project)

This is a high-utility, console-based medical database application designed for real-world hospital store management. 
It simulates an enterprise inventory system that helps storekeepers and nurses track critical hospital supplies, handle daily stock intake, and monitor shortage thresholds.

## What it does

* **Add New Items / Restock**: Safely register critical medical supplies with zero risk of duplicate entry data corruption.
* **Deduct Stock (Nurse Intake)**: Allows healthcare staff to withdraw exact quantities of items while strictly blocking negative inventory states.
* **Live Automated Alerts**: Scans stock levels in real time to flag low supplies or completely empty critical resources instantly.
* **Persistent Hard Drive Storage**: Saves data directly to a local file, ensuring critical hospital metrics survive system shutdowns and reboots.

## What I learned from this

* **Advanced File Handling**: Mastering C++ stream manipulation (`fstream`, `ifstream`, `ofstream`) to build a persistent flat-file database architecture.
* **String Parsing & Tokenization**: Using text streams (`stringstream`) and delimiter chopping (`getline`) to safely separate complex string elements.
* **Robust Exception Safety**: Implementing runtime crash guards (`if (line.empty()) continue;` and `stoi` sanitization) to prevent unexpected buffer crashes.
* **Transactional Integrity**: Designing a file-swapping runtime algorithm (reading, modifying, staging in a temporary file, and renaming) to safely update structural data.
* **UI/UX for Non-Programmers**: Stripping down complex database tracking parameters into natural, plain-text notifications easily understood by busy clinical staff.

## Files in the project

* **main.cpp** → Contains the complete system logic, menu dashboard loops, and transaction processors.
* **inventory.txt** → The persistent flat-file database sheet that holds live inventory records in a standardized (`Name:Quantity:Limit`) schema.

## How it works

You boot up the program (fully cross-compatible with desktop Code::Blocks or mobile Cxxdroid), and use a menu dashboard to:
1. **Add New Item / Restock**: Input item name, current store count, and low-stock alert thresholds.
2. **Deduct Item**: Track nurse withdrawals instantly via a foolproof name-based lookup loop.
3. **Check Low Stock / Finished Alerts**: Run background diagnostics to see urgent inventory shortages displayed instantly.
4. **Exit System**: Safely close out operations.

## About me

I’m a Computer Science student specializing in building high-utility, practical software solutions. 
This project marks a massive milestone in my development journey, transitioning from building casual gameplay systems to engineering secure, transactional database architectures optimized for low-spec deployment environments.

## Note:

This database engine is fully production-ready, highly optimized, and meticulously crash-guarded to handle unexpected user inputs safely.

