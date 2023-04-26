def same_data_type(a, b):
    if type(a) == type(b):
        return True
    else:
        return False

my_list = [1, 2, 3, 4, 5];
my_list1 = (2,1, 2, 3, 4, 5);

 
print(same_data_type(my_list,my_list1))
//print(same_data_type(5,10))