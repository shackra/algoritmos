{
  description = "Un flake para ejemplos de implementación de algoritmos";

  inputs = {
    git-hooks.url = "github:cachix/git-hooks.nix";
    nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/*";
  };

  outputs =
    {
      self,
      nixpkgs,
      git-hooks,
    }:
    let
      forAllSystems =
        function:
        nixpkgs.lib.genAttrs
          [
            "x86_64-linux"
            "x86_64-darwin"
          ]
          (
            system:
            function (
              import nixpkgs {
                inherit system;
              }
            )
          );

    in
    {
      checks = forAllSystems (pkgs: {
        pre-commit-check = git-hooks.lib.${pkgs.system}.run {
          src = builtins.path {
            path = ./.;
            name = "source";
          };
          hooks = {
            nil.enable = true;
            clang-format = {
              enable = true;
              files = "(\\.c$)|(\\.h$)";
            };
            clang-tidy.enable = true;
            cmake-format.enable = true;

            trim-trailing-whitespace.enable = true;
            check-case-conflicts.enable = true;
            end-of-file-fixer.enable = true;
          };
        };
      });
      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {
          packages =
            with pkgs;
            [
              cmake
              cmake-language-server
              gcc15Stdenv
              clang-tools
              gdb

              nil
              just
            ]
            ++ self.checks.${pkgs.system}.pre-commit-check.enabledPackages;

          inherit (self.checks.${pkgs.system}.pre-commit-check) shellHook;
        };
      });
    };
}
