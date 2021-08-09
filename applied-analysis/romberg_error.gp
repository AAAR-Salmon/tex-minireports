set terminal pdfcairo
set output "romberg_error.pdf"
set datafile separator ","

set logscale xy
set xtics 2
set ytics 10
unset mxtics

set format y "10^{%L}"

set grid xtics ytics mytics

plot "romberg_error.csv" every :::0::0 using 2:4 with linespoints title "k=0", \
     "romberg_error.csv" every :::1::1 using 2:4 with linespoints title "k=1", \
     "romberg_error.csv" every :::2::2 using 2:4 with linespoints title "k=2", \
     "romberg_error.csv" every :::3::3 using 2:4 with linespoints title "k=3", \
     "romberg_error.csv" every :::4::4 using 2:4 with linespoints title "k=4"
