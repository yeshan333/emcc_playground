// 处理编译生成的胶水层在微信层面不兼容的部分

const fs = require('fs');
const args = process.argv.slice(2);

if(args.length != 2) {
  console.log('Usage: node wechat_env_transformer.js <input> <output>');
  process.exit(1);
}

const input = args[0]
const output = args[1]

console.log(`Transforming ${input} to ${output}`);

const origin_text = fs.readFileSync(input, 'utf8');
const converted_text = origin_text
.replace(/wasmBinaryFile\s*\?\?=.*;/, 'wasmBinaryFile = "/unalign.wasm";')
.replace(/var result = await instantiateAsync/, 'var result = await instantiateAsyncInWeChat');

fs.writeFileSync(output, converted_text, 'utf8');