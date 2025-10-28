A simple C++ program to manage and query Amazon inventory data.

#	Build the program:
make
# Creates the executable.


#	Run the program:
make run
#Runs the program


#	Run tests:
make test
# Compiles and runs the unit tests


# Clean build artifacts:
make clean
# Removes all compiled executable


#	Search for a product by Inventory ID:
> find <inventory_id>
# Looks up a single product using its unique inventory ID.


#	Search for products by Category:
> find category <category_name>
# Lists all products that belong to the given category.


#	Help:
help
# lists all the commands


#	Quit:
quit
# Quits the program


#	Lag:
auto runs
# It takes a long while to log on first boot