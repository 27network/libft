{
  description = "dev-env for 42 projects";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils = {
      url = "github:numtide/flake-utils";
    };
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils
  }: flake-utils.lib.eachDefaultSystem
    (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        stdenv = pkgs.stdenvAdapters.useMoldLinker pkgs.clang17Stdenv;
      in
      {
        devShell = (pkgs.mkShell.override { inherit stdenv; }) {
          buildInputs = with pkgs; [
            SDL2
            readline
            vulkan-headers
            vulkan-loader
            vulkan-tools
          ];

          LD_LIBRARY_PATH="${pkgs.vulkan-loader}/lib";

          nativeBuildInputs = with pkgs; [
            cloc
            doxygen
            norminette
            valgrind
            gdb
          ];
        };
      }
    );
}
# vim: ts=2 sw=2 et

