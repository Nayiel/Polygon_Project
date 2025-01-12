# Polygon_Project
This project aim to dertermine by twos differents methods if a given point is in a given polygon or not. 

The idea of the first method, is to cast a infinite line from the given point and count the number of time it cross the polygon. If is an even number, the point does not belong to the polygon and if it is odd, the point belongs to it. This is the method so called scanline or ray casting. 

The test file include a main() function that test is different point are in a given square. Then it tests the last point to see if it's in Belgium or not. 

The belgium.data file is a rewrite into a suitable format of a geojson file which could be find in the include folder. We did try first to parse directly the geojson file with json parser and jsmn parser but eventually we failed. 

