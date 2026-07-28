**Overview**
- Purpose: Create, manage, and synchronize processes from user code.
- Key concepts: parent vs child, PID (process id), exit status, blocking vs non-blocking waits.

**fork()**
- What it does: Creates a new process by duplicating the caller. The new process is the child.
- High-level workflow:
	- Kernel allocates a new task structure copying the parent's memory context (copy-on-write usually).
	- Both processes continue from the next instruction; return value differentiates them: 0 in child, child's PID in parent, -1 on error.
- Typical use: spawn a child to run different code while parent continues or waits.

**exit() / _exit()**
- What it does: Terminates the calling process, returning an exit status to the kernel.
- High-level workflow:
	- Flush or skip stdio depending on `exit()` vs `_exit()` (use `_exit()` in child after `fork()` to avoid stdio duplication issues).
	- Kernel records exit status and state becomes "zombie" until parent collects it.

**getpid() and getppid()**
- `getpid()`: returns the caller's process id (PID).
- `getppid()`: returns the parent process id (PPID).
- Use cases: logging, PID-based coordination, or creating unique names/resources.

**wait() / waitpid()**
- What they do: Let a parent collect a child's exit status and release kernel resources.
- High-level workflow:
	- Parent calls `wait()`/`waitpid()`.
	- If child already exited (zombie), kernel immediately returns child's PID and status.
	- If child still running, `wait()` blocks the parent (unless WNOHANG used with `waitpid()`).
	- On success, return value is child's PID; status encodes exit code or signal info.
- Typical options: `WNOHANG` (non-blocking), `WUNTRACED` (report stopped children), `WEXITSTATUS()` to extract the code.

**Common workflows**
- Spawn-and-wait (simple): `fork()` → child does work and `exit()` → parent `wait()`s and reads status.
- Spawn-and-detach: `fork()` → parent continues without waiting; child must be reaped by another mechanism (or becomes orphan and adopted by `init`/`systemd`).
- Exec pattern: `fork()` → child calls an `exec*()` variant to replace its image; parent optionally `wait()`s.

**Errors and return values (quick)**
- `fork()`: returns -1 on failure (no child created).
- `getpid()/getppid()`: always return non-negative PIDs.
- `wait()/waitpid()`: -1 on error, 0 with WNOHANG if no child has exited.


