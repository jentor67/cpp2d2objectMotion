gnuplot -persist <<-EOFMarker 
plot "/home/john/temp/2d2Object_cpp_output2.txt" using 1:14 title "E-xN distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-1.txt" using 1:14 title "E-xN -10u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-2.txt" using 1:14 title "E-xN -100u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-3.txt" using 1:14 title "E-xN -400u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-4.txt" using 1:14 title "E-xN -1000u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-5.txt" using 1:14 title "E-xN -2000u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-6.txt" using 1:14 title "E-xN -1500u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-7.txt" using 1:14 title "E-xN -1200u distance" with lines, "" with points, \
"/home/john/temp/2d2Object_cpp_output2-8.txt" using 1:14 title "E-xN -800u distance" with lines, "" with points
EOFMarker
