

set logging file gdb_log.txt
set logging on output
set args urls.txt

break main
#awatch *0x102c46
#b *0x0000000000002c46

break GetRecipes
break ParseHtmlNode
break Datatable
break saveWebsite
break HashFunction
break sender
break write_callback

#break curl_easy_init
#break curl_easy_perform
#break curl_easy_cleanup

#break *0x102020
#awatch *0x102020

set follow-fork-mode child
