all: emcc xmake
	mkdir -p logs
emcc:
	emcc --check hello_world.c
	emcc -fsanitize=undefined -v hello_world.c
xmake:
	xmake f -p wasm -v
	xmake -v | tee logs/xmake_compile.log
diff:
	diff build/wasm/wasm32/release/hello_world.js a.out.js
api-example:
	emcc api_example.c -o api_example.js -v -sMODULARIZE -sEXPORTED_RUNTIME_METHODS=ccall
websocket:
	emcc -v -g -gsource-map --source-map-base=http://localhost:5500/ -sWEBSOCKET_DEBUG -sNO_EXIT_RUNTIME tests/websocket/test_websocket_send.c --js-library js-library/library_websocket.js -o index.html
websocket-test: websocket
	npx serve .
clean:
	xmake clean
	rm -rf .xmake
	rm -rf build
	rm a.*
	rm -f *.wasm
	rm -f *.js
	rm -f *.html