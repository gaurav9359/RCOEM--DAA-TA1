# RCOEM-DAA-TA1

***

### Name- Gaurav Pathak 
### subject- DAA (TA1)  
### Roll Number- A40 
### Branch- CSE(A) 

***

##### <ins> Aim </ins> - Implement a solution for Finding a summation of elements from a matrix.

***
##### <ins> Example </ins> - Accept a 2D matrix dimension. Populate using random number [non-zero], Accept any five dimension values from the user for example [1,1] [4,10] 10,7] [15,3] [20,18] Check the region covered by these points in the matrix.Calculate the boundary by either considering all points or ignoring few points which may not come on boundary [convex hull] .Find sum of elements in the region.


### <ins> Theory </ins>

suppose we have taken the matrix of any size and we have to find the point inside a specified polygon with specific points , then we will take each points and check weather the given is inside the polygon or outside by using algorithm of convex Hull , In the given problem if the point is inside the polygon then we have to add the point into some variable initiated with 0 else we have to ignore the point . by using this idea the code is written.

In the code attached, first we declared the matrix of 30 X 30 and filled it with random integers ,then by using the vector inside vector we declared the points that we have to take as input and perform our operation. Once the input is given by user , we iterate through all the element inside the matrix and checked all the element one by one that wheather it is inside the area generated by the points of the user or not . If the element is inside the area then we'll have to add that element into the variable sum that is initialized by sum(i.e sum=0). If the element is not present then we'll simply have to ignore that point . Once all the element is checked then we'll have to return the sum.

Sort the given points along with the query point in the increasing order of their 1st cordinate values. Set the bottom-left point as the start point and top-right point as the end point of the convex hull.Iterate over all the points and find out the points, forming the convex polygon, that lies in between the start and endpoints in the clockwise direction. Store these points in a vector. Iterate over all the points and find out the points, forming the convex polygon, that lies in between the start and endpoints in the counter-clockwise direction. Store these points in the vector.Check if the query point exists in the vector then the point lies outside the convex hull , ignore the point.If the point doesn’t exist in the vector, then the point lies inside the convex hull , add this point into the sum.
