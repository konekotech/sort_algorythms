from setuptools import setup, find_packages

setup(
    name="mypysort",
    version="1.0.0",
    author="konekotech",
    packages=find_packages(),
    # 依存するサードパーティのパッケージをここに記述します
    install_requires=[
        # 例: "requests", "numpy", など
    ],
    include_package_data=True,
)
