<!-- Generated: concise, actionable guidance for AI code contributors -->
# Copilot instructions — ArchSpiral

Purpose: quick, project-specific guidance for an AI coding agent to be immediately productive working on this small C/SDL project.

1) Big picture
- Single-file C application: `ArchSpiral.c` contains `main()` and the rendering loop. It uses SDL2 to create a window and draw points that form an Archimedes-style spiral.
- Data flow: CPU computes coordinates (nested loops over ZI and XIi), then calls SDL_RenderDrawPoint for each pixel; finally SDL_RenderPresent displays the frame.
- Why structured this way: the code is intentionally minimal and procedural — changes should keep that simple style unless migrating to a larger architecture.

2) Critical developer workflows (Windows)
- Build (MSYS2/MinGW): install SDL2 (pacman), then compile:
  - gcc ArchSpiral.c -o ArchSpiral.exe -lmingw32 -lSDL2main -lSDL2 -lm
  - or use `sdl2-config` where available: gcc ArchSpiral.c -o ArchSpiral.exe `sdl2-config --cflags --libs` -lm
- Build (MSVC):
  - cl /I"C:\path\to\SDL2\include" ArchSpiral.c /link /LIBPATH:"C:\path\to\SDL2\lib" SDL2.lib SDL2main.lib
- Debug in VS Code: open `.vscode/launch.json` and set `program` to `${workspaceFolder}/ArchSpiral.exe` (the template exists already). Use the `cppvsdbg` configuration.

3) Project-specific conventions & patterns
- Single-file, macro-driven config: `WIDTH` and `HEIGHT` are top macros — update rendering math using these macros, not hard-coded literals.
- Loop/variable style: loops use variables like `ZI` and `XIi`; follow the existing terse naming for small/local variables and keep changes localized.
- Floating math: the code uses `double` and a local `PI` constant. Preserve `double` precision for visual math unless profiling proves otherwise.
- SDL usage: initialization, renderer creation, draw calls, event loop and cleanup follow a clear pattern — mirror this sequence when adding features.

4) Integration points & external dependencies
- SDL2 is required at build and runtime. The repo contains no package management; document any added dependencies in a README or PR.
- No tests or CI found; manual build/run is the primary validation.

5) Concrete examples & editing hints
- Change drawing color: call `SDL_SetRenderDrawColor(renderer, r, g, b, 255);` before the drawing loop.
- Add another visual layer: compute new YT variation and call `SDL_RenderDrawPoint` with different offsets/scale — keep heavy loops CPU-bound and avoid allocating per-pixel.
- Error handling: tests in-place use fprintf + SDL_GetError(); when adding new SDL calls follow the same pattern (check return, print SDL_GetError, cleanup and return non-zero).

6) Files to inspect (high value)
- `ArchSpiral.c` — main program and rendering logic (single source of truth).
- `.vscode/launch.json` — edit `program` to point to built exe for debugging.
- `argv.json` — VS Code runtime args; generally do not change unless adjusting VS Code behavior.

7) Quick checklist for PRs from an AI agent
- Keep changes minimal and local to `ArchSpiral.c` unless adding documented new files.
- Build locally using one of the commands above and confirm a window appears.
- Update `.vscode/launch.json` in your branch only if you change debug program path; avoid altering global `argv.json` without reason.

If anything here is unclear or you want more examples (build scripts, MSVC project file, or a README with install steps), tell me which area to expand. 
