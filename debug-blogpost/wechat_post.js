async function instantiateAsyncInWeChat(binary, binaryFile, imports) {
    // 修改为微信的加载方式
    return WebAssembly.instantiate(binaryFile, imports)
}