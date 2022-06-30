/**
 * focaccia.cpp
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 1
 * Winter 2021
 *
 * Project Description : Printing the correct amount of ingredients needed to make foccacia bread, based on
 * the number of people that are served and the total cost of the ingredients
 * 
 * Project UID: 302fa9f14bd8266589c43c3129048565d11aa124
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {
    
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    // calculate no. of loaves to be made based on the no. of people entered
    const double PEOPLE_PER_LOAF = 4.0;
    int number_of_loaves = 0;
    number_of_loaves = ceil(people/ PEOPLE_PER_LOAF);
    
    // calculate no. of bags of flour required to make the focaccia loaves
    const double CUPS_PER_LOAF = 5.0;
    const double CUPS_PER_BAG = 20.0;
    int no_flour_bags;
    no_flour_bags = ceil((number_of_loaves * CUPS_PER_LOAF)/ CUPS_PER_BAG);
    
    // calculate no. of packages of yeast required to make the focaccia loaves
    const double YEAST_TEASPOON_LOAF = 1.75;
    const double YEAST_TEASPOON_PACKAGE = 2.25;
    int no_yeast_package;
    no_yeast_package = ceil((number_of_loaves * YEAST_TEASPOON_LOAF)/
        YEAST_TEASPOON_PACKAGE);
    
    // calculate no. of canisters of salt required to make the focaccia loaves
    const double SALT_TEASPOON_LOAF = 1.875;
    const double SALT_PER_TEASPOON = 5.0;
    const double SALT_PER_CANISTER = 30.0;
    int no_salt_canister;
    no_salt_canister = ceil((number_of_loaves * SALT_TEASPOON_LOAF *
        SALT_PER_TEASPOON)/ SALT_PER_CANISTER);
    
    // calculate bottles of olive oil required to make the focaccia loaves
    const double OLIVEOIL_TABLESPOON_LOAF = 2.0;
    const double OLIVEOIL_PER_TABLESPOON = 14.8;
    const double OLIVEOIL_PER_BOTTLE = 500.0;
    int no_oliveoil_bottles;
    no_oliveoil_bottles = ceil((number_of_loaves * OLIVEOIL_TABLESPOON_LOAF *
        OLIVEOIL_PER_TABLESPOON)/ OLIVEOIL_PER_BOTTLE);
    
    // calculate total cost of ingredients required to make the focaccia loaves
    double total_cost;
    total_cost = (no_flour_bags * 2.69) + (no_yeast_package * 0.40 ) +
    (no_salt_canister * 0.49 ) + (no_oliveoil_bottles * 6.39 );
    
    /* Printing out the amount of ingredients required to make the focaccia
     loaves and the total cost of the ingredients */
    cout << "You need to make: " << number_of_loaves << " " <<
        pluralize("loaf", "loaves", number_of_loaves) << " " << "of focaccia";
    cout << endl << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    cout << no_flour_bags << " " << pluralize("bag", "bags",
        no_flour_bags) << " " << "of flour" << endl;
    cout << no_yeast_package << " " << pluralize("package", "packages",
        no_yeast_package) << " " << "of yeast" << endl;
    cout << no_salt_canister << " " << pluralize("canister", "canisters",
        no_salt_canister) << " " << "of salt" << endl;
    cout << no_oliveoil_bottles << " " << pluralize("bottle", "bottles",
        no_oliveoil_bottles) << " " << "of olive oil";
    cout << endl << endl;
    cout << "Total expected cost of ingredients: " << "$" << total_cost;
    cout << endl << endl;
    cout << "Have a great socially-distanced party!";
    
    return 0;
    
    
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
