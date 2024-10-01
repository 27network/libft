{
  description = "libft-neo, a reimplementation of the C standard library functions";

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
        stdenv = pkgs.stdenvAdapters.useMoldLinker pkgs.llvmPackages_19.stdenv;
      in
      {
        devShell = (pkgs.mkShell.override { inherit stdenv; }) {
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

