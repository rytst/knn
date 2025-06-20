import polars as pl
from sklearn.model_selection import train_test_split


def main():
    df = pl.read_csv("../data/yXT_wine.csv", has_header=False)

    y = df.select(pl.col("column_1")).to_numpy().flatten()
    X = df.drop("column_1").to_numpy()

    X_train, X_test, y_train, y_test = train_test_split(X, y, stratify=y)

    train_df = pl.from_numpy(X_train)
    train_df.insert_column(0, pl.Series(y_train))

    test_df = pl.from_numpy(X_test)
    test_df.insert_column(0, pl.Series(y_test))

    print("Training data")
    print(train_df)

    print("Test data")
    print(test_df)

    train_df.write_csv("../data/train_test_data/train.csv", include_header=False)
    test_df.write_csv("../data/train_test_data/test.csv", include_header=False)


if __name__ == "__main__":
    main()
