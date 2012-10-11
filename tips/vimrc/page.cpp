sy on
set et 
set ts=4
set sts=4
set sw=4
set nu

set cindent

let g:map_leader = '\'

autocmd FileType c,cpp :nmap <Leader>c :make %< <CR>
autocmd FileType c,cpp :nmap <Leader>r :!./%< <CR>

autocmd FileType java :compiler javac
autocmd FileType java :nmap <Leader>c :make % <CR>
autocmd FileType java :nmap <Leader>r :!java %< <CR>
