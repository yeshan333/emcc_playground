simple:
	emcc fib.c -o fib.html

with-dwarf:
	emcc -g -v fib.c -o fib.html

with-sourcemap-and-dwarf:
	emcc -g -v fib.c -o fib.html -gsource-map --source-map-base=http://localhost:3000/

clean:
	rm -f *.wasm
	rm -f *.js
	rm -f *.html
	rm -f *.map

fault-debug:
	emcc -g -v unalign.cc -o unalign.html -gsource-map --source-map-base=http://localhost:3000/ -sSAFE_HEAP=1

wechat-dev:
	emcc -g -v unalign.cc -o unalign.html -gsource-map --source-map-base=http://localhost:3000/ -sSAFE_HEAP=1 --pre-js wechat_pre.js --post-js wechat_post.js

# 处理下胶水 js 文件在微信环境不兼容的 API
translate-glue:
	node wechat_transformer.js unalign.js unalign_wechat_env.js