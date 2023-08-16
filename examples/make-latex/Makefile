PAPER    := assignment.pdf
TEX_SUFS := .aux .log .nav .out .snm .toc .vrb .fdb_latexmk .bbl .blg .fls
GITID    := $(shell git describe --always 2> /dev/null)
FIGURES  := $(shell find *.png -type f)

$(info $$GITID is [${GITID}])                                                                                                              



%.pdf:%.tex assignment.tex common.tex $(FIGURES)
ifdef GITID
	./vc
else
	test -s vc.tex || { echo "vc.tex file does not exist (and this is not a git repo)!"; exit 1; }
endif
	pdflatex $<

all: $(PAPER)

clean:
	$(RM) $(foreach suf, ${TEX_SUFS}, $(PAPER:.pdf=${suf}))
ifdef GITID
	$(RM) vc.tex
endif
	$(RM) $(PAPER)

