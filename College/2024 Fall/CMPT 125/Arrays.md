Passing an array into a function passes the address of the first value in the array. Therefore, despite passing by value, you are giving a mutable reference of the array to this function. 

Why is this a thing???