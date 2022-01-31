LATEX = lualatex

TARGET = report

all:
	$(MAKE) latex
	$(MAKE) latex

latex:
	$(LATEX) -interaciton=batchmode $(TARGET)

clean:
	-rm $(TARGET).aux $(TARGET).log
