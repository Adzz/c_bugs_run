# C Bugs Run

[C Bugs. C Bugs run. Run bugs run.](https://www.youtube.com/watch?v=DID8B2yk5lY)

## What?

C/C++ debugger as per [this blogpost](https://blog.tartanllama.xyz/writing-a-linux-debugger-setup/)

### Running the bloody thing

On an M1 mac you gotta use docker:

```sh
./setup
```

(ensure the file is executable and that you have docker installed.)

It uses a volume so you can write files in your editor and have them appear in docker.

### Running the debugger

In the docker container run, inside `/debugger` (which should be the default)
```sh
 cmake . && make all
```

You should see an executable called `minidbg` and at least one example program we can debug called `hello`.

```sh
 ./minidbg hello
```
