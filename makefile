.PHONY: clean
.PHONY: All

ExecPath=./Executables
SourcePath=./SourceFiles

All: $(ExecPath)/Myecho $(ExecPath)/Mypwd $(ExecPath)/Mycp $(ExecPath)/Mymv


$(ExecPath)/Myecho: $(SourcePath)/Myecho.c
	gcc -o $@ $<
$(ExecPath)/Mypwd: $(SourcePath)/Mypwd.c
	gcc -o $@ $<
$(ExecPath)/Mycp: $(SourcePath)/Mycp.c
	gcc -o $@ $<
$(ExecPath)/Mymv: $(SourcePath)/Mymv.c $(SourcePath)/Return_Dest_Path.c
	gcc -o $@ $^

clean:
	@rm $(ExecPath)/*
