{
  description = "a flake for sysfo";

  inputs.nixpkgs.url = "github:nixos/nixpkgs";
  inputs.flake-compat = { url = "github:edolstra/flake-compat"; flake = false; };

  outputs = { self, nixpkgs, flake-compat }:
    let
      supportedSystems = [ "x86_64-linux" "i686-linux" "aarch64-linux" "x86_64-darwin" ];
      forAllSystems = f: nixpkgs.lib.genAttrs supportedSystems (system: f system);
    in
    {
      overlay = final: prev:
        with final; {
          sysfo = stdenv.mkDerivation {
            pname = "sysfo";
            version = "1.0";

            src = ./.;

            buildPhase = ''
              make
            '';

            checkPhase = ''
              $out/bin/sysfo -V > /dev/null
            '';

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
