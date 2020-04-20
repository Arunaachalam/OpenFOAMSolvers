Info << "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
	IOobject
	(
		"transportProperties",
		runTime.constant(),
		mesh,
		IOobject::MUST_READ,
		IOobject::NO_WRITE
	)
);

dimensionedScalar nu
(
	transportProperties.lookup("nu")
);
dimensionedScalar epsilon0
(
	transportProperties.lookup("epsilon0")
);
dimensionedScalar mobility
(
	transportProperties.lookup("mobility")
);
dimensionedScalar density
(
	transportProperties.lookup("density")
);


Info << "Reading field static Voltage\n" << endl;
volScalarField statvolt
(
	IOobject
	(
		"voltage",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);


Info << "Reading field space charge\n" << endl;
volScalarField rhoN
(
	IOobject
	(
		"rhoN",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);

Info << "Reading field space charge\n" << endl;
volScalarField rhoP
(
	IOobject
	(
		"rhoP",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);


Info << "Calculating particle voltage" << endl;
volScalarField partvoltN
(
	IOobject
	(
		"particlefieldN",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);

Info << "Calculating particle voltage" << endl;
volScalarField partvoltP
(
	IOobject
	(
		"particlefieldP",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	),
	mesh
);

Info << "Calculating field rhoFlux\n" << endl;
surfaceScalarField rhoFluxN
(
	IOobject
	(
		"rhoFluxN",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	),
	-mobility*mesh.magSf()*fvc::snGrad(partvoltN)
);

Info << "Calculating field rhoFlux\n" << endl;
surfaceScalarField rhoFluxP
(
	IOobject
	(
		"rhoFluxP",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	),
	-mobility*mesh.magSf()*fvc::snGrad(partvoltP)
);
