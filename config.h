#define TABLE \
	 /*web addresses*/\
	X("https?://.+") \
	Y("port web '\\0'") \
	/*man files*/\
	X("([a-zA-Z0-9\\-_]+)\\(([0-9a-zA-Z]+)\\),?") \
	Y("port man \\2 \\1") \
	 /*local include files*/\
	X("#include \"([a-zA-Z0-9]+\\.h)\"") \
	Y("port edit \\1") \
	 /*standard include files*/\
	X("#include <([a-zA-Z0-9]+\\.h)>") \
	Y("port edit $(std_inc \\1)") \
	 /*addressed files: should work with gcc error output*/\
	X("(.+):([0-9]+):([0-9]+):.*") \
	Y("port 2a_edit \\1 \\2 \\3") \
	 /*addressed files: should work with grep -n */\
	X("(.+):([0-9]+|(/|\\?).+).*") \
	Y("port a_edit \\1 \\2") \
	 /*pdf files*/\
	X(".*\\.(pdf|PDF)\\*?") \
	Y("port pdf \\0") \
	 /*img files*/\
	X(".*\\.(jpe?g|png)\\*?") \
	Y("port img \\0") \
	 /*libreoffice documents*/ \
	X(".*\\.(doc|docx|ppt|pptx|xls|xlsx|odt|ods|odp)\\*?") \
	Y("port libreoffice \\0") \
	 /*Chinese characters--no punctuation => shorter phrase*/ \
	X("[\u4E00-\u9FA5\u3400-\u4DBF\u20000-\u2A6DF\u2A700-\u2B73F\u2B740-\u2B81F\u2B820-\u2CEAF\uF900-\uFAFF\u2F800-\u2FA1F]+") \
	Y("port chinese_short \\0") \
	 /*Chinese characters--with punctuation or newline => longer phrase*/ \
	X("[\u4E00-\u9FA5\u3000-\u303F\u3400-\u4DBF\u20000-\u2A6DF\u2A700-\u2B73F\u2B740-\u2B81F\u2B820-\u2CEAF\uF900-\uFAFF\u2F800-\u2FA1F\uFF01-\uFF64\n]+") \
	Y("port chinese_long '\\0'") \
	 /*Everything else is text*/\
	X(".*") \
	Y("port edit \\0")
