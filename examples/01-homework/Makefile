PAPER    := 01-assignment.pdf
TEX_SUFS := .aux .log .nav .out .snm .toc .vrb .fdb_latexmk .bbl .blg .fls
GITID    := $(shell git describe --always 2> /dev/null)

$(info $$GITID is [${GITID}])                                                                                                              


%.pdf:%.tex 01-assignment.tex
ifdef GITID
	./vc
else
	test -s vc.tex || { echo "vc.tex file does not exist (and this is not a git repo)!"; exit 1; }
endif
	latexmk -pdf $<

all: $(PAPER)

clean:
	$(RM) $(foreach suf, ${TEX_SUFS}, $(PAPER:.pdf=${suf}))
ifdef GITID
	$(RM) vc.tex
endif
	$(RM) $(PAPER)

