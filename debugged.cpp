#include "./linenoise.h"
#include <string>
#include <iostream>
#include <unistd.h>

// class debugger {
//   public:
//     debugger (std::string prog_name, pid_t pid) :
//       m_prog_name{std::move(prog_name)},
//       m_pid{pid}
//       {}

//   void run();

// private:
//   std::string m_prog_name;
//   pid_t m_pid;
// };

// void debugger::run() {
//   int wait_status;
//   auto options = 0;
//   waitpid(m_pid, &wait_status, options);

//   char* line=nullptr;
//   while((line = linenoise("minidbg> ")) != nullptr) {
//     handle_command(line);
//     linenoiseHistoryAdd(line);
//     linenoiseFree(line);
//   }
// }

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Program name not specified!";
    return -1;
  }

  auto prog = argv[1];

  auto pid = fork();

  if (pid == 0) {
    // we are in the child process, execute the program we are debugging.
    ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
    execl(prog, prog, nullptr);
  }
  else if (pid >=1) {
    //We are in the parent process here. execute the debugger.
    std::cout << "Started debugging process" << pid << "\n\n";
    // debugger dbg(prog, pid);
    // dbg.run();
  }
}
