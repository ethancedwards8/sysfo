{
  description = "a flake for sysfo";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  inputs.flake-compat = { url = "github:edolstra/flake-compat"; flake = false; };

  outputs = { self, nixpkgs, flake-compat }:
    let
      forAllSystems = nixpkgs.lib.genAttrs nixpkgs.lib.systems.flakeExposed;
    in
    {
      overlay = final: prev:
        with final; {
          sysfo = stdenv.mkDerivation {
            __contentAddressed = true;
            pname = "sysfo";
            version = "1.0";

            src = ./.;

            # buildPhase = ''
            #   make CC=clang
            # '';

            # checkPhase = ''
            #   $out/bin/sysfo -V > /dev/null
            # '';

            installPhase = ''
              mkdir -p $out/bin
              cp sysfo $out/bin/sysfo
            '';
          };
        };

      defaultPackage = forAllSystems (system: (import nixpkgs {
        inherit system;
        overlays = [ self.overlay ];
      }).sysfo);
    };
}
