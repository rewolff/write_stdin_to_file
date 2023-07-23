# write_stdin_to_file
Simple program to write stdin to a file.


It requires one argument, the file to write to. 

Sometimes simply writing the input to a file is required. 
`tee somefile` then still produces output, as does `dd of=somefile`

Redirecting to devnull would be possible but complicates things. 
This does one thing and it does it well. 


TODO: when the write returns less than the bytes-to-be-written, 
now the rest is ignored. That normally doesn't happen. But handling
the case would be good. 
