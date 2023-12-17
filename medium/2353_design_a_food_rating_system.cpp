#include <iostream>
#include <vector>
#include <map>
#include <set>

// Runtime: 452ms;      Beats 43.06% of users with C++
// Memory: 159.24MB;    Beats 88.52% of users with C++
using RatingPairType = std::pair<int, std::string>;
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
class FoodRatings
{
private:
    // stores the rating and cuisine for each food item
    std::map<std::string, RatingPairType> food_map;

    // stores a sets of foods by cuisine where each set is sorted by rating
    std::map<std::string, std::set<RatingPairType>> cuisine_map;

    struct type_cuisine_rating
    {
        std::string cuisine;
        int rating;
    };

    std::map<std::string, type_cuisine_rating> food_ratings;

public:
    // constructor to build data in the object
    FoodRatings(std::vector<std::string> &foods, std::vector<std::string> &cuisines, std::vector<int> &ratings)
    {
        size_t arr_size = foods.size();
        for (int i = 0; i < arr_size; i++)
        {
            food_map[foods[i]] = RatingPairType(ratings[i], cuisines[i]);
            // store ratings as a negative value
            // std::set stores value in descending order; easier to get the higest rated food in a cuisine
            cuisine_map[cuisines[i]].insert(RatingPairType(-ratings[i], foods[i]));
        }
    }

    // update food rating
    void changeRating(std::string food, int newRating)
    {
        RatingPairType &current_pair = food_map[food];
        cuisine_map[current_pair.second].erase(RatingPairType(-current_pair.first, food));
        current_pair.first = newRating;
        cuisine_map[current_pair.second].insert(RatingPairType(-newRating, food));
    }

    std::string highestRated(std::string cuisine)
    {
        return cuisine_map[cuisine].begin()->second;
    }
};

int main(int argc, char *argv[])
{
    // std::vector<std::string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    // std::vector<std::string> cuisine = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    // std::vector<int> ratings = {9, 12, 8, 15, 14, 7};

    std::vector<std::string> foods = {"tjokfmxg", "xmiuwozpmj", "uqklk", "mnij", "iwntdyqxi", "cduc", "cm", "mzwfjk"};
    std::vector<std::string> cuisine = {"waxlau", "ldpiabqb", "ldpiabqb", "waxlau", "ldpiabqb", "waxlau", "waxlau", "waxlau"};
    std::vector<int> ratings = {9, 13, 7, 16, 10, 17, 16, 17};

    FoodRatings *obj = new FoodRatings(foods, cuisine, ratings);
    obj->changeRating("tjokfmxg", 19);
    std::cout << obj->highestRated("waxlau") << std::endl;
    obj->changeRating("uqklk", 7);
    std::cout << obj->highestRated("waxlau") << std::endl;
    std::cout << obj->highestRated("waxlau") << std::endl;
    obj->changeRating("tjokfmxg", 14);
    std::cout << obj->highestRated("waxlau") << std::endl;
    std::cout << obj->highestRated("waxlau") << std::endl;
    obj->changeRating("tjokfmxg", 4);
    std::cout << obj->highestRated("waxlau") << std::endl;
    obj->changeRating("mnij", 18);
    std::cout << obj->highestRated("waxlau") << std::endl;

    return 0;
}