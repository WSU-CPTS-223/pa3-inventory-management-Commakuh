A simple C++ program to manage and query Amazon inventory data.

#	Build the program:
make

Creates the executable.


#	Run the program:
make run

Runs the program


#	Run tests:
make test

Compiles and runs the unit tests


# Clean build artifacts:
make clean

Removes all compiled executable


#	Search for a product by Inventory ID:
> find <inventory_id>

Looks up a single product using its unique inventory ID.


#	Search for products by Category:
> find category <category_name>

Lists all products that belong to the given category.


#	Help:
help

lists all the commands


#	Quit:
quit

Quits the program


#	Lag:
auto runs

It takes a long while to log on first boot


#	Data Cleanup Decisions:

Some products have missing category data — these are labeled as "NA"

Some products have multiple categories, separated by "|".
Each category entry is handled individually in the category table

Whitespace is trimmed from all CSV fields

Empty product IDs or names are skipped entirely to prevent invalid entries

#	Testing Approach:

All data structure testing was done using cassert in tests/test_HashTable.cpp

Insertion and lookup — Verify that inserted key-value pairs can be retrieved correctly

Missing key lookup — Ensure the hash table returns false when the key doesn’t exist

Collision handling — Force collisions with small capacity to confirm both keys still work

Duplicate insert — Confirm that inserting an existing key overwrites old value


All tests passed successfully.