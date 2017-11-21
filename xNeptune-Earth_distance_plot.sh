gnuplot -persist <<-EOFMarker 
plot [26345400:26377200] [0:400000000] "/home/john/temp/2d2Object_cpp_output2.txt" using 1:14 title "E-xN distance", \
"/home/john/temp/2d2Object_cpp_output2-1.txt" using 1:14 title "E-xN -10u distance", \
"/home/john/temp/2d2Object_cpp_output2-2.txt" using 1:14 title "E-xN -100u distance", \
"/home/john/temp/2d2Object_cpp_output2-3.txt" using 1:14 title "E-xN -400u distance", \
"/home/john/temp/2d2Object_cpp_output2-4.txt" using 1:14 title "E-xN -1000u distance", \
"/home/john/temp/2d2Object_cpp_output2-5.txt" using 1:14 title "E-xN -2000u distance", \
"/home/john/temp/2d2Object_cpp_output2-6.txt" using 1:14 title "E-xN -1500u distance", \
"/home/john/temp/2d2Object_cpp_output2-7.txt" using 1:14 title "E-xN -1200u distance", \
"/home/john/temp/2d2Object_cpp_output2-8em.txt" using 1:14 title "E-xN -800u distance"
EOFMarker
