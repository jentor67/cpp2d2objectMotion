gnuplot -persist <<-EOFMarker 
plot [] [0:200000000000] "/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 1:12 title "Earth radius"with lines, "" with points, \
"/home/jmajor/temp/2d2Object_cpp_output2-8em.txt" using 1:13 title "xNeptune radius" with lines, "" with points
EOFMarker
