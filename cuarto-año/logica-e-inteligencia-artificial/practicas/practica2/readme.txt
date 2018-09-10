This directory holds the 3 components of the SVMultln tool package:

(1) a subdirectory "styles" with
- the document class "svmultln.cls",
- the class option "svlnbip.clo" for the LNBIP series,
- the Springer MakeIndex style file "sprmindx.sty"
- a BibTeX style "splncs.bst" (same as for the well known
  Springer LNCS series and borrowed from there)

(2) a subdirectory "author" containing

    - a subdirectory "instructions" with
      -- the pdf file "quickstart.pdf" with "essentials" for
         an easy implementation of the "SVMultln" package (1 page)
      -- the pdf file "typeinst.pdf" with style and
         coding instructions specific to the subject area
         or book series you are writing for.
      -- the corresponding LaTeX source "typeinst.tex" that also can
         serve as a template for your contribution.

      Tip: Follow these instructions to set up your files, to type in
           your text and to obtain a consistent formal style; use these
           pages as checklists before you submit your ready-to-print
           manuscript.

    - a subdirectory "templates" with
      -- the sample root file "lnbip.tex"
         with preset class options, packages and coding examples;
      -- the corresponding pdf file "lnbip.pdf"
         as an example of a contribution to a LNBIP volume

      Tip: Copy all these files to your working directory,
           run LaTeX and produce your own example *.dvi file, or
           run pdfLaTeX and produce your own example *.pdf file,
           rename the template files as you see fit and
           use them for your own input.

    - a link to the directory "styles" (see position (1) above)

(3) a subdirectory "editor" containing

    - a subdirectory "instructions" with
      -- the pdf file "edinst.pdf" with step-by-step instructions
         for the volume editor containing all information on
         the workflow and listing the requirements
      -- a ZIP archive "lnbip2de.zip" that demonstrates how to
         generate the front- and backmatter (preface, table of
         contents, and author index) - thus "faking" a complete
         volume without combining all contributions to a single run
         --- "lnbipde2.tex" (LaTeX source, use it as template)
         --- "preface.tex" (LaTeX source of preface)
         --- "sprmindx.sty" (makeindex style for Springer layout)
         --- "lnbipde2.pdf" (resulting output)

    - a subdirectory "templates" with
      -- the sample root file "editor.tex"
         with preset class options, packages and coding examples;
      -- the sample text files
         --- "preface.tex" (preface),
         --- "author.tex" (first contribution),
         --- "author2.tex" (second contribution),
      -- the resulting pdf file "editor.pdf" as an example of a
         "complete volume"

         Tip: Copy all these files to your working directory,
              run LaTeX and produce your own example *.dvi file, or
              run pdfLaTeX and produce your own example *.pdf file,
              rename the template files as you see fit and
              use them as emulation for your own input.

    - a link to the directory "styles" (see position (1) above)

Contact in case of general problems and questions on the workflow
        lnbip@springer.com  (LNBIP editorial office)

        in case of TeXnical problems (installation and usage of package)
        texhelp@springer.de
