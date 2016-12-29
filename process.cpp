#include "process.hpp"

Process::Process(const string_type &command, const string_type &path,
                 std::function<void(const char* bytes, size_t n)> read_stdout,
                 std::function<void(const char* bytes, size_t n)> read_stderr,
                 bool open_stdin, size_t buffer_size):
                 closed(true), read_stdout(read_stdout), read_stderr(read_stderr), open_stdin(open_stdin), buffer_size(buffer_size) {
  open(command, path);
  async_read();
}

Process::~Process() {
  close_fds();
}

Process::id_type Process::get_id() {
  return data.id;
}

bool Process::write(const std::string &data) {
  return write(data.c_str(), data.size());
}
