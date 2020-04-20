//voltage solve

//solve
//(
//	fvm::laplacian(statvolt)
//);

//Negative Particles
solve
(
	fvm::laplacian(partvoltN) + rhoN/epsilon0
);

rhoFluxN = (fvc::interpolate(U) & mesh.Sf()) + mobility*mesh.magSf()*fvc::snGrad(partvoltN);

solve
(
	fvm::ddt(rhoN) + fvm::div(rhoFluxN,rhoN)
);

//Positive Particles
solve
(
	fvm::laplacian(partvoltP) + rhoP/epsilon0
);

rhoFluxP = (fvc::interpolate(U) & mesh.Sf()) + mobility*mesh.magSf()*fvc::snGrad(partvoltP);

solve
(
	fvm::ddt(rhoP) + fvm::div(rhoFluxP,rhoP)
);


runTime.write();