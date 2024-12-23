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
clean:
	xmake clean
	rm -rf .xmake
	rm -rf build
	rm a.*