set terminal pdfcairo
set output "trap_simpson_error.pdf"
set datafile separator ","

set logscale xy
set xtics 2
set ytics 10
unset mxtics

set format y "10^{%L}"

set grid xtics ytics mytics

plot "trap_simpson_error.csv" using 1:3 with linespoints title "trapezoid", \
     "trap_simpson_error.csv" using 1:5 with linespoints title "simpson"
