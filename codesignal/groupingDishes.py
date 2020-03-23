# 
# groupingDishes
# 
# You are given a list dishes, where each element consists of a list of strings beginning with the name of the dish, followed by all the ingredients used in preparing it. You want to group the dishes by ingredients, so that for each ingredient you'll be able to find all the dishes that contain it (if there are at least 2 such dishes).
# 
# Return an array where each element is a list beginning with the ingredient name, followed by the names of all the dishes that contain this ingredient. The dishes inside each list should be sorted lexicographically, and the result array should be sorted lexicographically by the names of the ingredients.
# 
# Example
# 
# For
#   dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
#             ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
#             ["Quesadilla", "Chicken", "Cheese", "Sauce"],
#             ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]
# the output should be
#   groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
#                             ["Salad", "Salad", "Sandwich"],
#                             ["Sauce", "Pizza", "Quesadilla", "Salad"],
#                             ["Tomato", "Pizza", "Salad", "Sandwich"]]
# For
#   dishes = [["Pasta", "Tomato Sauce", "Onions", "Garlic"],
#             ["Chicken Curry", "Chicken", "Curry Sauce"],
#             ["Fried Rice", "Rice", "Onions", "Nuts"],
#             ["Salad", "Spinach", "Nuts"],
#             ["Sandwich", "Cheese", "Bread"],
#             ["Quesadilla", "Chicken", "Cheese"]]
# the output should be
#   groupingDishes(dishes) = [["Cheese", "Quesadilla", "Sandwich"],
#                             ["Chicken", "Chicken Curry", "Quesadilla"],
#                             ["Nuts", "Fried Rice", "Salad"],
#                             ["Onions", "Fried Rice", "Pasta"]]
# 

def groupingDishes(dishes):
    ingreds = {}
    # build hash of ingredients and their dishes
    for dish in dishes:
        for ingred in dish[1:]:
            if ingred not in ingreds:
                ingreds[ingred] = []
            ingreds[ingred].append(dish[0])
            
    ans = []
    # sort the lists and convert into a 2D array
    keys = ingreds.keys()
    keys.sort()
    for k in keys:
        # skip any ingredients with less than 2 dishes
        if len(ingreds[k]) < 2:
            continue
        # sort the dishes
        ingreds[k].sort()
        # insert the ingredient at the beginning of the list
        ingreds[k].insert(0,k)
        # append our list to the answer list
        ans.append(ingreds[k])
            
    return ans

