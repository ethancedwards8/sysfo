{
  description = "a flake for sysfo";

  inputs.nixpkgs.url = "github:nixos/nixpkgs";

  outputs = { self, nixpkgs }: {

    defaultPackage.x86_64-linux = 

    with import nixpkgs { system = "x86_64-linux"; };

    stdenv.mkDerivation {
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
}
