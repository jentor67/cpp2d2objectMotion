gnuplot -persist <<-EOFMarker 
plot [-200000000000:200000000000] [-200000000000:200000000000] "/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 2:3 title "Sun" with lines, "" with points, \
 "/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 4:5 title "Earth" with lines, "" with points, \
 "/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 6:7 title "Moon" with lines, "" with points, \
 "/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 8:9 title "Jupiter" with lines, "" with points, \
 "/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 10:11 title "xNeptune" with lines, "" with points
EOFMarker
