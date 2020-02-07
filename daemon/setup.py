import setuptools


setuptools.setup(
    name="daemon",
    version="0.0.1",
    author="Sergio Schvezov",
    author_email="sergio.schvezov@canonical.com",
    description="A simple daemon that prints the user it is running under",
    scripts=["daemon"],
)
