关键改进
- 错误处理：使用 `handle_error` 函数集中处理错误信息，便于维护和提高代码的可读性。
- 缓冲区处理：确保读取的字符串以 \0 结束，以防止输出未定义的内容。
- 检查 send 和 read 的返回值：确保发送和接收的数据都没有错误，并相应处理。
- 使用常量定义：通过宏定义端口和缓冲区大小，方便后续修改。

安全性注意事项
- 输入验证：在生产环境中，建议对客户端发送的数据进行验证，以防止恶意输入。
- 使用 TLS/SSL：在真实应用中，建议使用 TLS/SSL 等加密层来保护数据传输。
- 限制连接数：可以使用 listen 函数的第二个参数来限制最大连接数，从而保护服务器不被恶意攻击。
- 资源管理：确保在异常情况下能正确释放资源，避免内存泄漏。
